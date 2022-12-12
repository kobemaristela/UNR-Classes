from django.urls import path
from dog_feeder import views


urlpatterns = [
    path('', views.index, name='index'),
    path('setBreakfast', views.set_breakfast),
    path('setLunch', views.set_lunch),
    path('setDinner', views.set_dinner),
    path('getBreakfast', views.get_breakfast),
    path('getLunch', views.get_lunch),
    path('getDinner', views.get_dinner),
    path('getTodayMeals', views.get_today_meals),
    path('resetMeals', views.reset_meals)    # Testing Purposes
]
