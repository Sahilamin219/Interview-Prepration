# Python3 program for demonstrating
# closing a coroutine
# Generators in Python -> use yield instead of return which gives a iterator

def print_name(prefix):
    print("Searching prefix:{}".format(prefix))
    try : 
        while True:
                name = (yield)
                if prefix in name:
                    print(name)
    except GeneratorExit:
            print("Closing coroutine!!")

corou = print_name("Dear")
corou.__next__()
corou.send("Atul")
corou.send("Dear Atul")
corou.close()
"""Output: 

Searching prefix:Dear
Dear Atul
Closing coroutine!!"""
#Chaining coroutines for creating pipeline
#Coroutines can be used to set pipes. We can chain together coroutines and push data through the pipe using send() method. A pipe needs :  
# Python3 program for demonstrating
# coroutine chaining

def producer(sentence, next_coroutine):
    '''
    Producer which just split strings and
    feed it to pattern_filter coroutine
    '''
    tokens = sentence.split(" ")
    for token in tokens:
        next_coroutine.send(token)
    next_coroutine.close()

def pattern_filter(pattern="ing", next_coroutine=None):
    '''
    Search for pattern in received token 
    and if pattern got matched, send it to
    print_token() coroutine for printing
    '''
    print("Searching for {}".format(pattern))
    try:
        while True:
            token = (yield)
            if pattern in token:
                next_coroutine.send(token)
    except GeneratorExit:
        print("Done with filtering!!")
        next_coroutine.close()

def print_token():
    '''
    Act as a sink, simply print the
    received tokens
    '''
    print("I'm sink, i'll print tokens")
    try:
        while True:
            token = (yield)
            print(token)
    except GeneratorExit:
        print("Done with printing!")

pt = print_token()
pt.__next__()
pf = pattern_filter(next_coroutine = pt)
pf.__next__()

sentence = "Bob is running behind a fast moving car"
producer(sentence, pf)
"""Output: 

I'm sink, i'll print tokens
Searching for ing
running
moving
Done with filtering!!
Done with printing!"""
