function slide(c, n){
    if (c===" ") return " ";
    let new_c = c.charCodeAt()+n;
    console.log("new_c "+new_c);
    if(c.charCodeAt() <= "Z".charCodeAt() &&
      new_c > "Z".charCodeAt()) return String.fromCharCode(c.charCodeAt()+n - 26);
    else if(c.charCodeAt() >= "a".charCodeAt() &&
      new_c > "z".charCodeAt()) return String.fromCharCode(c.charCodeAt()+n - 26);
    else return String.fromCharCode(c.charCodeAt()+n);
}

function solution(s, n) {
    var answer = '';
    return [...s].map((el) => slide(el, n)).join('')
    return answer;
}