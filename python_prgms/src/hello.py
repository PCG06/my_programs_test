# Python script to print my basic info

my_name = "PCG"
my_age = 18
my_hobbies = ["binging TV shows", "reading history", "programming", "playing shooter games"]

if len(my_hobbies) > 1:
    my_hobbies.sort(key=str.lower)
    hobbies_str = ", ".join(my_hobbies[:-1]) + " and " + my_hobbies[-1] + "."
else:
    hobbies_str = my_hobbies[0] + "."

print("My name is", my_name)
print("I am {} years old".format(my_age))
print("My hobbies are", hobbies_str)
