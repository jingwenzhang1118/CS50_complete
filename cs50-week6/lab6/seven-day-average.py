from collections import OrderedDict
from datetime import date, datetime, timedelta
import csv
import os
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)
    headers = reader.fieldnames
    print(headers)

    #transform reader to a list of dictionaries, so it can be used multiple times.
    # reader cannot be applied to loops multiple times.

    data = list(reader)
    lastline = len(data) - 1
    current_date = data[lastline]['date']
    current_date = datetime.strptime(current_date,'%Y-%m-%d').date()
    target_date = current_date - timedelta(days=14)
    # datetime.strptime(current_date,'%Y-%m-%d').date() - timedelta(days=14)
    print(current_date, target_date)

    cases_now = []
    cases_now_new = []
    for dic in data:
        if datetime.strptime(dic['date'],'%Y-%m-%d').date() > target_date:
            cases_now.append(dic)
    # cases_now_new = [[dic['date'], dic['state'], dic['cases']] for dic in cases_now]


    cases_until_last_day = []
    for dic in data:
        if target_date <= datetime.strptime(dic['date'],'%Y-%m-%d').date() < current_date:
            cases_until_last_day.append(dic)
    




    '''
    for dic in data:
        for date in dic:
            dic['date'] = datetime.strptime(dic['date'],'%Y-%m-%d').date()
            if date not in dates:
                dates.append(dic['date'])
    recent_date=max(dates) - timedelta(days=14)
    print(recent_date)

    for

    recent_date = max(data[0]['date'])
    print(recent_date)
    print(data[0]['date'])

    print(data['date'])


    dates = []
    for row in reader:
        # %Y is 4 digit, %y is 2 digit.
        row[headers[0]] = datetime.strptime(row[headers[0]],'%Y-%m-%d').date()
        dates.append(row[headers[0]])
    recent_date=max(dates) - timedelta(days=14)
    print(recent_date)
    today = date.today()
    print(str(today))


    cases = {}
    for row in reader:
        if row[headers[0]] > recent_date:
            print(row[headers[0]])
            cases.append(row)
    print(cases)

    '''






    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    ...


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    ...


main()
