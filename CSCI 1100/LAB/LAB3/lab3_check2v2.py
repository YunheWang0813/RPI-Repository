
def points(num_wins, num_draw):
    p=num_wins*3+num_draw
    return p

def goal_adv(goals_for, goals_against):
    g=goals_for-goals_against
    return g

## Process results for Germany

num_wins = 2
num_losses = 1 
num_draw = 0
goals_for = 7
goals_against = 2

print "Germany"
print "Win:", num_wins, "Lose:", num_losses, "Draw:", num_draw
print "Total number of points:", points(num_wins,num_draw), "Goal advantage:", goal_adv(goals_for,goals_against)

## Process results for USA

num_wins = 1
num_draw = 1
num_losses = 1 
goals_for = 4
goals_against = 4

print "USA"
print "Win:", num_wins, "Lose:", num_losses, "Draw:", num_draw
print "Total number of points:", points(num_wins,num_draw), "Goal advantage:", goal_adv(goals_for,goals_against)

## Process results for Argentina

num_wins = 3
num_draw = 0
num_losses = 0 
goals_for = 6
goals_against = 3

print "Argentina"
print "Win:", num_wins, "Lose:", num_losses, "Draw:", num_draw
print "Total number of points:", points(num_wins,num_draw), "Goal advantage:", goal_adv(goals_for,goals_against)

## Process results for England

num_wins = 0
num_draw = 1
num_losses = 2 
goals_for = 2
goals_against = 4

print "England"
print "Win:", num_wins, "Lose:", num_losses, "Draw:", num_draw
print "Total number of points:", points(num_wins,num_draw), "Goal advantage:", goal_adv(goals_for,goals_against)
