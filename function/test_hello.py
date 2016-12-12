#!/usr/bin/env python

def test_hello_ext():
    "Test calling the extension function greet()"

    import hello_ext
    # should call the function greet
    s = hello_ext.greet()
    print s
    assert s == 'hello, world', 'expected: \'hello, world\''

if __name__ == '__main__':
    test_hello_ext()
