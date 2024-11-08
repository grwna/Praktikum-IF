import tester
tester.start("input.csv")

file = open("input.csv", "r")
lines = file.readlines()
departments = []
salaries = []
for line in lines[1:]:
    line_data = line.strip().split(",")
   
    if line_data[1] not in departments:
        departments.append(line_data[1])
        salaries.append(int(line_data[2]))
    else:
        index = departments.index(line_data[1])
        salaries[index] += int(line_data[2])

if len(salaries) == 0: 
    print("Data kosong")
else: 
    for salary in salaries: 
        print(salary)
    print(sum(salaries)//len(salaries))

tester.end("input.csv")