function isChange(ch, idx){
    if(idx === 0 || ch === " "){
        return true;
    }
    return false;
}

function solution(s) {
    return [...s.split('')].map((el, idx, arr)=>{
        const next = arr[idx-1];
        if(isChange(next, idx)) {
            return el.toUpperCase()
        } else return el.toLowerCase()
    }).join('')
}