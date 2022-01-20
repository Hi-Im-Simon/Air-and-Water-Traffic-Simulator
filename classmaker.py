# provide one argument on execution (name of the new class)
import sys


name = sys.argv[1]

file = open(f'classes/{ name }.hpp', 'w+')
file.write(
f"""#ifndef { f'{ name.upper() }_HPP' }
#define { f'{ name.upper() }_HPP' }

class { name } {{
    public:

    protected:

}};

#endif"""
)
file.close()

file = open(f'classes/{ name }.cpp', 'w+')
file.write(
f"""#include "{ name }.hpp"

"""
)
file.close()
