str = raw_input("Please input a string\n")
str.strip()
str = str.replace(' ','')

if str == str[::-1]:
    print "Yes"
else:
    print "No"
