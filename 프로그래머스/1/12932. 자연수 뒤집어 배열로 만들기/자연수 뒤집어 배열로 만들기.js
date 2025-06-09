function solution(n) {
    return Array.from([...n.toString()].reverse(), (el, _)=>Number(el))
}