function checkBurger(burger){
    var size = burger.length;
    if(size < 4) return false;
    if(burger[size-4]===1 &&
      burger[size-3]===2 &&
      burger[size-2]===3 &&
      burger[size-1]===1) return true;
}

function solution(ingredient) {
    var answer = 0;
    var burger = [];
    for(var i=0;i<ingredient.length;i++){
        burger.push(ingredient[i]);
        if(checkBurger(burger)){
            burger.splice(-4, 4);
            answer++;
        }
    }
    return answer;
}