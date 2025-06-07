function solution(food) {
    var answer = "0";
    for(var i = food.length - 1; i > 0 ; i--){
        if(food[i] >= 2){
            answer = i.toString().repeat(Math.floor(food[i] / 2))
            + answer + i.toString().repeat(Math.floor(food[i] / 2))
        }
    }
    return answer;
}