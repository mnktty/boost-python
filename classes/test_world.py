#!/usr/bin/env python

def test_world():
    import world_ext
    w = world_ext.World()
    expected = 'What a nice day !'
    w.set(expected)
    s = w.greet()
    print s
    assert s == expected, 'expected: {0}'.format(expected)

if __name__ == '__main__':
    test_world()

# eof
    
