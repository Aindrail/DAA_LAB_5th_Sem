/*
A company manufactures a fixed number of laptops every day. However, if some defect is encountered during the testing of a laptop, it is labeled as “illegal” and is not counted in the laptop count of the day. Given the cost to manufacture each laptop, its label as "illegal" or "legal", and the number of legal laptops to be manufactured each day, find the maximum cost incurred by the company in a single day in manufacturing all the laptops.

 

Note that if a laptop is labeled as illegal, its manufacturing cost is still incurred by the company, even though it is not included in the laptop count. Also, days are only taken into when the daily laptop count has been completely met. If there are no such days, the answer is 0. 

 

For example, let's say there are n = 5 laptops, where cost = [2, 5, 3, 11, 1]. The labels for these laptops are labels = ["legal", "illegal", "legal", "illegal", "legal"]. Finally, the dailyCount = 2, which means that the company needs to manufacture 2 legal laptops each day. The queue of laptops can be more easily viewed as follows:

cost 2, "legal"

cost 5, "illegal"

cost 3, "legal"

cost 11, "illegal"

cost 1, "legal"

 

On the first day, the first three laptops are manufactured in order to reach the daily count of 2 legal laptops. The cost incurred on this day is 2 + 5 + 3 = 10. On the second day, the fourth and fifth laptops are manufactured, but because only one of them is legal, the daily count isn't met, so that day is not taken into consideration. Therefore, the maximum cost incurred on a single day is 10.

 
Function Description

Complete the function maxCost in the editor below.

 

maxCost has the following parameter(s):

    int cost[n]:  an array of integers denoting the cost to manufacture each laptop

    string labels[n]: an array of strings denoting the label of each laptop ("legal" or "illegal")

    int dailyCount: the number of legal laptops to be manufactured each day

Returns:

    int: the maximum cost incurred in a single day of laptop manufacturing

 

Constraints

1 ≤ n ≤ 105

0 ≤ cost[i] ≤ 104

1 ≤ dailyCount ≤ n

labels[i] ∈ {"legal", "illegal"}

The first line contains an integer, n, denoting the number of laptops and the size of the array cost.

Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, cost[i], denoting the cost to manufacture each laptop.

The next line again contains an integer, n, denoting the size of the array labels.

Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, labels[i], denoting the label of each laptop ("legal" or "illegal").

The last line contains an integer, dailyCount, denoting the number of legal laptops to be manufactured each day

Sample Input For Custom Testing

1
2
1
illegal
1
Sample Output

0
Explanation

Here, there is only 1 laptop manufactured, where cost = [1] and labels = ["illegal"]. Also, dailyCount = 1. Since the only laptop manufactured is labeled as illegal, there is no day where the daily count for legal laptops is met, so no days are taken into consideration. Therefore, the answer is 0.

Sample Input For Custom Testing

5
0
3
2
3
4
5
legal
legal
illegal
legal
legal
1
Sample Output

5
Explanation

Here, there are n = 5 laptops manufactured, and the dailyCount = 1. The laptops have the following costs and labels:

cost 0, "legal"

cost 3, "legal"

cost 2, "illegal"

cost 3, "legal"

cost 4, "legal"

 

On the first day, one legal laptop is manufactured, incurring a cost of 0. Another legal laptop is manufactured on the second day, incurring a cost of 3. On the third day, there are two laptops manufactured (because one of them is illegal), incurring a cost of 2 + 3 = 5. Finally, on the fourth day, one legal laptop is manufactured, incurring a cost of 4. The greatest cost incurred in a single day is 5, which happened on the third day. Therefore, the answer is 5.




*/

int maxCost(vector<int> cost, vector<string> labels, int dailyCount) {
    int n = cost.size();
    vector<int> legal;
    vector<int> illegal;
    for(int i = 0; i < n; i++){
        if(labels[i] == "legal"){
            legal.push_back(cost[i]);
        }
        else{
            illegal.push_back(cost[i]);
        }
    }
    sort(legal.begin(), legal.end());
    sort(illegal.begin(), illegal.end());
    int ans = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < legal.size()){
        int sum = 0;
        for(int j = 0; j < dailyCount; j++){
            if(i < legal.size()){
                sum += legal[i];
                i++;
            }
        }
        ans = max(ans, sum);
    }
    return ans;
}

/*
convert python code to cpp
def nearlySimilarRectangles(sides):
    gcd = lambda a, b: gcd(b, a % b) if b > 0 else a
    d = defaultdict(int)
    for w, h in sides:
        z = gcd(w, h)
        d[(w // z, h // z)] += 1
    return sum((x * (x - 1)) // 2 for x in d.values())
*/
def nearlySimilarRectangles(sides):
    gcd = lambda a, b: gcd(b, a % b) if b > 0 else a
    d = defaultdict(int)
    for w, h in sides:
        z = gcd(w, h)
        d[(w // z, h // z)] += 1
    return sum((x * (x - 1)) // 2 for x in d.values())

