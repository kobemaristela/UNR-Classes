from django.shortcuts import render
from django.views.decorators.csrf import csrf_exempt
from dog_feeder.models import Fed
from dog_feeder import controller
from datetime import date

@csrf_exempt
def index(request):
    # Create new entry if missing date
    today = list(Fed.objects.filter(today=date.today()))
    if not today:
        new_day = Fed.objects.create(today=date.today())
        new_day.save()


    meals = Fed.objects.all().values()
    fed, missed = 0, 0
    for meal in meals:
        if meal['is_fed_breakfast']:
            fed += 1
        else:
            missed += 1

        if meal['is_fed_lunch']:
            fed += 1
        else:
            missed += 1

        if meal['is_fed_dinner']:
            fed += 1
        else:
            missed += 1


    context = {
    'fed': fed,
    'missed': missed,
    'today': date.today(),
    }
    return render(request, 'index.html', context)


@csrf_exempt
def set_breakfast(request):
    if request.method == "POST":
        return controller.set_breakfast()

@csrf_exempt
def set_lunch(request):
    if request.method == "POST":
        return controller.set_lunch()

@csrf_exempt
def set_dinner(request):
    if request.method == "POST":
        return controller.set_dinner()

@csrf_exempt
def get_breakfast(request):
    if request.method == "GET":
        return controller.get_breakfast()

@csrf_exempt
def get_lunch(request):
    if request.method == "GET":
        return controller.get_lunch()

@csrf_exempt
def get_dinner(request):
    if request.method == "GET":
        return controller.get_dinner()


@csrf_exempt
def get_today_meals(request):
    if request.method == "GET":
        return controller.get_today_meals()


@csrf_exempt
def rest_meals(request):
    if request.method == "POST":
        return controller.rest_meals()