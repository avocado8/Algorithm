function solution(cards1, cards2, goal) {
    var answer = '';
    var index1 = 0;
    var index2 = 0;
    for(var i=0;i<goal.length;i++){
        if (cards1[index1] == goal[i]){
            index1++;
        }
        else if (cards2[index2] == goal[i]){
            index2++;
        }
        else return "No";
    }
    return "Yes";
}