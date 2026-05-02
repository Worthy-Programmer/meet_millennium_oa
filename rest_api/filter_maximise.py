# Challenge 2: The Filter and Maximize

# Background: You are analyzing medical records to find the patient with the highest blood pressure in a specific city.
# API Endpoint: GET https://jsonmock.hackerrank.com/api/medical_records?city={city}
# Data Structure:

# {
#   "total_pages": 5,
#   "data": [
#     { "id": 1, "userName": "John", "vitals": { "bloodPressureDiastole": 120 } },
#     ...
#   ]
# }

import requests

def maximise_bp(city: str, url = 'https://jsonmock.hackerrank.com/api/medical_records'):

    params = {'city': city, 'page': 1}

    max_bp: int = -1

    while True:
        r = requests.get(url, params=params)

        if not r.ok: break

        b = r.json()

        for d in b.get('data', []):
            max_bp = max( d.get('vitals', {}).get('bloodPressureDiastole', -1) , max_bp)


        if params['page'] >= b.get('total_pages', 0): break
        params['page'] += 1

    print(f"Maximum BP in city {city} is {max_bp}")

maximise_bp('')