function solution(s) {
    var answer = '';
    let idx = 0;
    var tmp = [...s.split('')];
    for(let i=0;i<tmp.length;i++){
        if(tmp[i] === " ") {
            answer += " ";
            idx = 0;
            continue;
        }
        if(idx % 2 === 0){
            answer += tmp[i].toUpperCase();
        } else answer += tmp[i].toLowerCase();
        idx++;
    }
    return answer;
}