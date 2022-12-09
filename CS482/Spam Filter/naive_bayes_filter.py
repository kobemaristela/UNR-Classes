# Import libraries
import numpy as np
import pandas as pd
import unicodedata
import argparse
import re
import itertools
import nltk
from nltk.corpus import stopwords
from nltk import word_tokenize
from nltk.stem import WordNetLemmatizer, LancasterStemmer

# Download stopwords & punkt
nltk.download('stopwords', quiet=True)
nltk.download('punkt', quiet=True)
nltk.download('wordnet', quiet=True)
nltk.download('omw-1.4')

class NaiveBayesFilter:
    def __init__(self, test_set_path):
        self.vocabulary = None
        self.training_set= None
        self.test_set = None
        self.p_spam = None
        self.p_ham = None
        self.test_set_path = test_set_path

    def read_csv(self):
        self.training_set = pd.read_csv('train.csv', sep=',', header=0, names=['v1', 'v2'], encoding = 'utf-8')
        self.test_set = pd.read_csv(self.test_set_path, sep=',', header=0, names=['v1', 'v2'], encoding = 'utf-8')

    # Remove all URLs - http/https
    def remove_urls(self, message):
        return re.sub(r'(www|http)\S+', '', message)

    # Remove all emails
    def remove_emails(self, message):
        regex_pattern = '[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}'
        return re.sub(regex_pattern, '', message)

    # Remove phone number
    def remove_phone_number(self, message):
        regex_pattern = '(?:\+?(\d{1,3}))?[-. (]*(\d{3})[-. )]*(\d{3})[-. ]*(\d{4})(?: *x(\d+))?'
        return re.sub(regex_pattern, '', message)
    
    def remove_bullets_numbering(self, message):
        return re.sub('[(\s][0-9a-zA-Z][.)]\s+|[(\s][ivxIVX]+[.)]\s+', ' ', message)

    # Tokenize words
    def tokenize_words(self, message):
        return word_tokenize(message)

    # Remove non-ascii
    def remove_non_ascii(self, message):
        return unicodedata.normalize('NFKD', message).encode('ascii', 'ignore').decode('utf-8', 'ignore')

    # Change text to lowercase
    def make_lowercase(self, message):
        return message.lower()

    # Remove special characters - punctuations
    def remove_symbols(self, message):
        return re.sub(r'[^\w\s]', '', message)

    # Replace numbers to text form
    def remove_numbers(self, message):
        return re.sub('\d+', '', message)

    # Remove stop words
    def remove_stopwords(self, message):
        return [text for text in message if text not in set(stopwords.words('english'))]

    # Stemmize Words
    def stemmize(self, message):
        stemmer = LancasterStemmer()
        return list(map(stemmer.stem, message))

    # Lemmatize Words
    def lemmatize(self, message):
        lemmatizer = WordNetLemmatizer()
        return list(map(lemmatizer.lemmatize, message))

    # Remove duplicates from list
    def remove_duplicates(self, wordlist):
        return [*set(wordlist)]

    def normalize_message(self, message):
        # Undergrad Implementation
        temp_message = message
        temp_message = self.make_lowercase(temp_message)
        temp_message = self.remove_urls(temp_message)
        temp_message = self.remove_emails(temp_message)
        temp_message = self.remove_phone_number(temp_message)
        temp_message = self.remove_numbers(temp_message)
        temp_message = self.remove_bullets_numbering(temp_message)
        temp_message = self.remove_non_ascii(temp_message)
        temp_message = self.remove_symbols(temp_message)
        temp_message = self.tokenize_words(temp_message)
        temp_message = self.remove_stopwords(temp_message)

        # Grad Implementation
        temp_message = self.stemmize(temp_message)
        temp_message = self.lemmatize(temp_message)

        return temp_message

    def combine_list(self, word_list):
        combine_list = list(itertools.chain.from_iterable(word_list))  # combine lists
        combine_list = self.remove_duplicates(combine_list) # Remove dups
        combine_list = [i for i in combine_list if i] # Remove empty strings

        return combine_list

    def data_cleaning(self):
        output_list = list(map(self.normalize_message, self.training_set['v2']))    # Normalize messages

        self.vocabulary = self.combine_list(output_list)    # Combine normalized messages into one list 

        # Vectorize and separate dataframes
        word_message = {word: [0] * len(self.training_set['v2']) for word in self.vocabulary}   # Create dictionary
        for index, message in enumerate(self.training_set['v2']):
            temp_message = self.normalize_message(message)
            for temp_word in temp_message:
                if temp_word in self.vocabulary:
                    word_message[temp_word][index] += 1     # increment if message found in vocab

        word_counts = pd.DataFrame(word_message)    # Create dataframe

        self.training_set = pd.concat([self.training_set, word_counts], axis=1)

    def fit_bayes(self):
        # Calculate P(Spam) and P(Ham)
        spam = self.training_set[self.training_set['v1'] == 'spam']
        ham = self.training_set[self.training_set['v1'] == 'ham']

        self.p_spam = len(spam) / len(self.training_set)
        self.p_ham = len(ham) / len(self.training_set)

        # Calculate Nspam, Nham and Nvocabulary
        n_vocabulary = len(self.vocabulary)
        n_spam = spam['v2'].apply(len).sum()
        n_ham = ham['v2'].apply(len).sum()

        # Laplace smoothing parameter
        alpha = 0.25 # Lower -> aided false positives

        # Calculate P(wi|Spam) and P(wi|Ham)
        self.param_spam = {word:0 for word in self.vocabulary}
        self.param_ham = {word:0 for word in self.vocabulary}

        for word in self.vocabulary:
            p_word_given_spam = (spam[word].sum() + alpha) / (n_spam + alpha * n_vocabulary)
            self.param_spam[word] = p_word_given_spam

            p_word_given_ham = (ham[word].sum() + alpha) / (n_ham + alpha * n_vocabulary)
            self.param_ham[word] = p_word_given_ham

    def train(self):
        self.read_csv()
        self.data_cleaning()
        self.fit_bayes()
    
    def sms_classify(self, message):
        '''
        classifies a single message as spam or ham
        Takes in as input a new sms (w1, w2, ..., wn),
        performs the same data cleaning steps as in the training set,
        calculates P(Spam|w1, w2, ..., wn) and P(Ham|w1, w2, ..., wn),
        compares them and outcomes whether the message is spam or not.
        '''

        msg = self.normalize_message(message)
        p_spam_temp = self.p_spam
        p_ham_temp = self.p_ham

        for word in msg:
            if word in self.param_spam:
                p_spam_temp *= self.param_spam[word]

            if word in self.param_ham: 
                p_ham_temp *= self.param_ham[word]

        if p_ham_temp > p_spam_temp:
            return 'ham'
        elif p_spam_temp > p_ham_temp:
            return 'spam'
        else:
            return 'needs human classification'

    def classify_test(self):
        '''
        Calculate the accuracy of the algorithm on the test set and returns 
        the accuracy as a percentage.
        '''
        self.train()

        # check = {
        #     'ham':0,
        #     'spam':0
        # }

        accuracy = 0
        self.test_set['guess'] = self.test_set['v2'].apply(self.sms_classify)
        total = self.test_set.shape[0]

        for row in self.test_set.iterrows():
            row = row[1]
            if row['v1'] == row['guess']:
                accuracy += 1
        #     else:
        #         check[row['v1']] += 1

        # print(check)  # check num of failed ham/spam - helps adjust laplace adjust parameter
        return accuracy / total * 100


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Naive Bayes Classifier')
    parser.add_argument('--test_dataset', type=str, default = "test.csv", help='path to test dataset')
    args = parser.parse_args()
    classifier = NaiveBayesFilter(args.test_dataset)
    acc = classifier.classify_test()
    print("Accuracy: ", acc)


