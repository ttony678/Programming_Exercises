#
# Stairs(optimized) AI version1.1 Analagous to Human Brain
# Mob Session 1
#
# Authors: Guthrie Price, Tony Lopez, Mathew Schaffrath
#

n = 6

def getInput(n):
  memoization = [1,2,4]
#  for i in range(n):
#    memoization.append(-1)

#  memoization[0] = 1
#  memoization[1] = 2
#  memoization[2] = 4

  countStairs(n, memoization)
	
  print("Solution:")
  print(memoization[n-1])
	

def countStairs(n, memo):
#  if(memo[n-1] != -1):
#    return memo[n-1]
  for i in range(3, n):
    #memo[i] = memo[i-1] + memo[i-2] + memo[i-3]
    memo.append(memo[i-1] + memo[i-2] + memo[i-3])

def countStairsRecursive(n, memo):
  if( 

  print("Solution Recursive : " + memoization[n-1])
	
getInput(n)
countStairsRecursive(n)






