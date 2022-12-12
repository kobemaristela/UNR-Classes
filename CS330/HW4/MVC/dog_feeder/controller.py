from dog_feeder.models import Fed
from datetime import date
from django.http import JsonResponse, HttpResponseRedirect
from django.urls import reverse


def set_breakfast():
    breakfast = Fed.objects.get(today=date.today())
    breakfast.is_fed_breakfast = True
    breakfast.save()
    return HttpResponseRedirect(reverse("index"))


def set_lunch():
    breakfast = Fed.objects.get(today=date.today())
    breakfast.is_fed_lunch = True
    breakfast.save()
    return HttpResponseRedirect(reverse("index"))


def set_dinner():
    breakfast = Fed.objects.get(today=date.today())
    breakfast.is_fed_dinner = True
    breakfast.save()
    return HttpResponseRedirect(reverse("index"))


def get_breakfast():
    return JsonResponse({
        'breakfast': Fed.objects.latest('today').is_fed_breakfast
    })


def get_lunch():
    return JsonResponse({
        'lunch': Fed.objects.latest('today').is_fed_lunch
    })


def get_dinner():
    return JsonResponse({
        'dinner': Fed.objects.latest('today').is_fed_dinner
    })


def get_today_meals():
    meals = Fed.objects.latest('today')
    return JsonResponse({
        'breakfast': meals.is_fed_breakfast,
        'lunch': meals.is_fed_lunch,
        'dinner': meals.is_fed_dinner,
    })


# Testing Purposes
def reset_meals():
    meals = Fed.objects.get(today=date.today())
    meals.is_fed_breakfast = True
    meals.is_fed_lunch = True
    meals.is_fed_dinner = True
    meals.save()
    return HttpResponseRedirect(reverse("index"))