#!/usr/bin/python -tt


def _compound_interest(principal=1000, rate=0.05, num_years=5):
    year = 1
    while year <= num_years:
        principal = principal * (1 + rate)
        print year, principal
        year += 1


def main():
    _compound_interest(500500, 0.04, 15)

if __name__ == "__main__":
    main()
