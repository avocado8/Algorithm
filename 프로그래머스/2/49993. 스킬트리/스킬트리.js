function isIn(ch, arr){
    for(let i of arr){
        if (ch===i) return true;
    }
    return false;
}

function solution(skill, skill_trees) {
    let answer = 0;
    for(let s of skill_trees){
        let tmp = [...s].filter((el)=>skill.includes(el));
        let sliced = skill.slice(0, tmp.length);
        if(tmp.join('')===sliced) answer++;
    }
    
    return answer;
}