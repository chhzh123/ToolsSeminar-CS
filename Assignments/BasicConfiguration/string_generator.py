import random
import string

lst = string.ascii_lowercase + string.ascii_uppercase + string.digits + '_,./+-*'

name = []
for i in range(1,100001):
	name_len = random.randint(1,25)
	name.append('({})'.format(str(i)) + ''.join(random.sample(lst,name_len)))

with open("name.txt","w") as outfile:
	outfile.write(''.join(name))