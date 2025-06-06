
function solution(s) {
    var answer = '';
    var letters = s.split("");
    letters.sort((a,b)=>a>b ? -1 : 1)
    answer = letters.join('')
    return answer;
}