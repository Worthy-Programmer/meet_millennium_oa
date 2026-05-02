# Challenge 3: Multi-Step Chaining (The "Join")

# Background: You are given an author's username. You need to find out how many articles they have written. However, the articles API only searches by author_id, not username.
# API 1 (Users): GET https://jsonmock.hackerrank.com/api/users?username={username} (Returns their ID)
# API 2 (Articles): GET https://jsonmock.hackerrank.com/api/articles?author_id={id} (Returns their articles)

# The Catch: You must successfully hit the first API, parse the result to extract an ID, and inject that ID into the URL for the second API.