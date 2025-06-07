function solution(s) {
    var answer = true;
    if(s.length == 4 || s.length ==6){
        var arr = s.split("");
        for(var i=0;i<s.length;i++){
            if(arr[i] < "0" || arr[i] > "9"){
                return false;
            }
        }
    } else return false;
    return answer;
}