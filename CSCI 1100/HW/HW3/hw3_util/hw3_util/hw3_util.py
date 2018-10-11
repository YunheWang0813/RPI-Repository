"""
   Utility functions for Homework #3 Fall 2014

   To use this module, first import it

   import hw3_util

"""

def read_fifa():
    """ Reads the file containing team scores, and returns a list.
        Each item in the list is a list containing:
            [team, games_played, 
             win, draw, loose, goals for, goals against]
    """
    
    teams = []
    for line in open("league_teams.txt"):
        m = line.strip().split("\t")
        if len(m) == 7:
            m[0] = m[0].strip()
            for i in range(len(m)):
                if i != 0:
                    m[i] = int(m[i])
            teams.append(m)
    return teams
