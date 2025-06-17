function solution(s) {
    const answer = [];
    let arr_s = s.slice(2, -2).split("},{").map((el)=>el.split(',').map(Number)).sort((a,b)=>a.length-b.length)
    console.log(arr_s)
    let prev = [];
    for(let i=0;i<arr_s.length;i++){
        let new_num = arr_s[i].filter((el)=>!prev.includes(el));
        answer.push(new_num[0]);
        prev = arr_s[i];
    }
    return answer;
}