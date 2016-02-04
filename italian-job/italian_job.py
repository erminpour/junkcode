#!/usr/bin/python -tt
"""italian_job.py

Given a CSV table of driving distances between various cities in
Italy (in km), Take any two cities as input and figure out the
shortest route to take, returning as output the list of cities to
drive through and the total distance in km.
"""
import sys
import exceptions
import getopt
import csv
import json
import networkx as nx

__author__ = "Victor Hugo Erminpour"
__license__ = "GPL"
__version__ = "1.0"
__email__ = "victorhugo@uchicago.edu"
__status__ = "Prototype"

# Globals
G = nx.Graph()
src_city = "Milan"
dst_city = "Padua"
infile = "italy-distances.csv"


def convert_str(s):
    try:
        return int(s)
    except exceptions.ValueError:
        return 0


def usage(exit_code):
    print "Usage: %s [options] <src_city> <dst_city>" % (sys.argv[0])
    print "\t-h | --help\tPrint this usage message."
    print "\t-i | --infile\tSpecify CSV infile."
    sys.exit(exit_code)


def parse_args():
    global src_city, dst_city, infile

    try:
        options, remainder = getopt.gnu_getopt(sys.argv[1:], \
            "hi:", ["help", "infile="])
    except getopt.GetoptError:
        usage(2)

    for opt, arg in options:
        if opt in ("-h", "--help"):
            usage(0)
        elif opt in ("-i", "--infile"):
            infile = arg

    # remainder args are src and dst cities
    if len(remainder) == 2:
        src_city = remainder[0]
        dst_city = remainder[1]


def setup_graph():
    global infile
    csv_fh = open(infile, "rb")
    csvReader = csv.DictReader(csv_fh)

    # iterate through each CSV file line
    for csv_line in csvReader:
        # iterate through CSV line values
        for city, distance in csv_line.items():
            # skip the first "Italian City" item
            if city == "Italian City":
                continue
            # add city and weight values to the undirected graph
            G.add_edge(csv_line["Italian City"], city, \
                weight=convert_str(distance))
    csv_fh.close()


def main():
    # parse cmdline arguments
    parse_args()

    # read the undirected weighted graph from the CSV file
    setup_graph()

    # get the shortest path and path length via networkx's
    # implementation of Dijkstra's Algorithm
    shortest_path = nx.dijkstra_path(G, src_city, dst_city)
    shortest_path_length = nx.dijkstra_path_length(G, src_city, dst_city)

    # dump JSON output to stdout
    json.dump(dict(cities=shortest_path, \
        distance=shortest_path_length), sys.stdout)
    sys.stdout.write("\n")

if __name__ == "__main__":
    sys.exit(main())
