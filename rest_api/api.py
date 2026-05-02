import requests

r = requests.get('https://api.github.com/events')
# r = requests.put('https://httpbin.org/put', data={'key': 'value'})
# r = requests.delete('https://httpbin.org/delete')
# r = requests.head('https://httpbin.org/get')
# r = requests.options('https://httpbin.org/get')

print(r.text)

# Adding parameter

# r = requests.get('https://httpbin.org/get', params={'key1': 'value1'})
print(r.url)

print(r.encoding)
print(r.ok)
print(r.json())

