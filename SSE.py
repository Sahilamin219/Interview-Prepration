import time
import json

def event_stream():
    k=10
    while True and k:
        k-=1
        time.sleep(2)  # Simulate a delay between messages
        notification = {"message": "New Notification!", "timestamp": time.time()}
        yield f"data: {json.dumps(notification)}\n\n"  # SSE format

def events():
    return event_stream()

a = events()

# # Print values yielded by the generator using a for loop
# for notification in a:
#     print(notification)
    
# # Get the next value from the generator
# notification = next(a)
# print(notification)
# # If you want to get more values, call next() again
# notification = next(a)
# print(notification)

# Convert the generator to a list (be cautious, since the generator is infinite)
notifications = list(a)
print(notifications)
