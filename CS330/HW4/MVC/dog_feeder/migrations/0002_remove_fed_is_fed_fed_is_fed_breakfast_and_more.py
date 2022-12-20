# Generated by Django 4.1.4 on 2022-12-12 04:13

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('dog_feeder', '0001_initial'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='fed',
            name='is_fed',
        ),
        migrations.AddField(
            model_name='fed',
            name='is_fed_breakfast',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='fed',
            name='is_fed_dinner',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='fed',
            name='is_fed_lunch',
            field=models.BooleanField(default=False),
        ),
    ]