#!/usr/bin/python

class Employee:
    'Common base class for all employees'
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1

    def displayCount(self):
        print "Total Employees: %d" % Employee.empCount

    def displayEmployee(self):
        print "Name:\t%s\nSalary:\t%s" % (self.name, self.salary)

def main():
    emp1 = Employee("Alice", "100,000")
    emp2 = Employee("Bob", "100,000")
    empList = [emp1, emp2]

    for emp in empList:
        emp.displayEmployee()
        emp.displayCount()

    ##
    ## Object attributes
    print '\nObject atrributes'
    print hasattr(emp1, 'name')
    print getattr(emp1, 'name')
    setattr(emp1, 'name', "Eve")
    print getattr(emp1, 'name')
    delattr(emp1, 'name')
    print hasattr(emp1, 'name')

if __name__ == '__main__':
    main()


