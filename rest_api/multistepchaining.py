# Challenge 3: Multi-Step Chaining (The "Join")

# Background: You are given an author's username. You need to find out how many articles they have written. However, the articles API only searches by author_id, not username.
# API 1 (Users): GET https://jsonmock.hackerrank.com/api/users?username={username} (Returns their ID)
# API 2 (Articles): GET https://jsonmock.hackerrank.com/api/articles?author_id={id} (Returns their articles)

# The Catch: You must successfully hit the first API, parse the result to extract an ID, and inject that ID into the URL for the second API.

import requests
def get_userid(name, url = 'https://jsonmock.hackerrank.com/api/users'):
    params = {'username': name}
    r = requests.get(url, params=params)
    if not r.ok: return -1

    d = r.json().get('data', [])
    
    if len(d) < 1: return -1
    return int(d[0].get('id', -1))

def get_articles(userid, url = 'https://jsonmock.hackerrank.com/api/articles'):
    params = {'author_id': userid, 'page': 1}

    article_count = 0
    while True:
        r = requests.get(url, params=params)
        if not r.ok: break

        b = r.json()

        article_count += len (b.get('data', []))

        if b.get('total_pages', 0) <= params['page']: break
        params['page'] += 1

    return article_count

# Another way
# def get_articles(userid, url = 'https://jsonmock.hackerrank.com/api/articles'):
#     params = {'author_id': userid}
#     r = requests.get(url, params=params)
#     if not r.ok: return 0
    
#     # Just grab the grand total directly from the first page's metadata!
#     return r.json().get('total', 0)


def get_article_count_from_name(name):
    user_id = get_userid(name)
    if user_id != -1:
        return get_articles(user_id)
    return 0