from django.db import models

class Fed(models.Model):
    is_fed_breakfast = models.BooleanField(default=False)
    is_fed_lunch = models.BooleanField(default=False)
    is_fed_dinner = models.BooleanField(default=False)
    today = models.DateField()
