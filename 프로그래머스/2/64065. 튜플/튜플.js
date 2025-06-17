function solution(s) {
    const answer = [];
    let arr_s = s.slice(2, -2).split("},{").map((el)=>el.split(',').map(Number)).sort((a,b)=>a.length-b.length)
    let seen = new Set();
    for(let i=0;i<arr_s.length;i++){
        let next = arr_s[i].find(num => !seen.has(num));
        answer.push(next);
        seen.add(next);
    }
    return answer;
}