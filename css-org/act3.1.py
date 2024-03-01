ages = [54, 89, 2, 47, 16, 28]

smallest_age = ages[0]

for age in ages:
  if age < smallest_age:
    smallest_age = age

print("Smallest age:", smallest_age)
