from concurrent.futures import ThreadPoolExecutor

# Initialize variables
buffer = []

# User Prompt
print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n Perfect Number Checker \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
num = int(input("Enter a number: "))
worker = int(input(f"Enter # of threads to spawn: "))

# Calculates if number is a factor 
def calcFactor(n):
    
    print(n)
    if num % n == 0:
        buffer.append(n)

# Spawn specied number of child threads
# https://docs.python.org/3/library/concurrent.futures.html
with ThreadPoolExecutor(max_workers=worker) as executor:
    # Executor automatically frees resources upon completion
    # shutdown(wait=True) already called upon exit

    results = executor.map(calcFactor,range(1,num-1)) # Iterable 1 to N-1 is divided into chunks and executed async to the function

# Return to parent process
if sum(buffer) == num and num != 1:
    print (f"{num} is a perfect number!")
else:
    print (f"{num} is NOT a perfect number!")