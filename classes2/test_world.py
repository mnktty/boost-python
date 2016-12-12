#!/usr/bin/env python

def test_world():
    import world_ext
    expected = 'What a nice day !'

    # specific ctor now enforced
    w = world_ext.World(expected)
    s = w.greet()
    print s
    assert s == expected, 'expected: {0}'.format(expected)

    # try with default ctor
    w = world_ext.World()
    expected = 'Empty World'
    s = w.greet()
    print s
    assert s == expected, 'expected: {0}'.format(expected)

if __name__ == '__main__':
    test_world()

# eof
    
