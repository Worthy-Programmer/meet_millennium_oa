'''
Background: You need to calculate the total goals scored by a specific football team during a given year.
API Endpoint: GET https://jsonmock.hackerrank.com/api/football_matches?year={year}&team1={team}
Data Structure:

{
  "page": 1,
  "total_pages": 2,
  "data": [
    { "team1": "Chelsea", "team2": "Everton", "team1goals": "2", "team2goals": "1" },
    ...
  ]
}

The Catch: The team1goals field is returned as a string instead of an integer, so you must cast it before doing math.
'''

import requests
from pprint import pprint

def aggregator(team1: str, year: int, url = 'https://jsonmock.hackerrank.com/api/football_matches'):


    total_goals = 0
    params={'team1': team1, 'year': year, 'page': 1}

    while True:
        r = requests.get(url, params = params)
        if (not r.ok): raise RuntimeError

        body  = r.json()

        for d in body.get('data', []):
            total_goals += int(d.get('team1goals', 0))

        #if params['page'] == body['total_pages']: break 
        if params['page'] >= body.get('total_pages', 0): break 

        params['page'] = params['page'] + 1

    
    return total_goals


print(aggregator('Chelsea', 2011))