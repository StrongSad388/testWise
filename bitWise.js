#!/usr/bin/env node
const nine = 9;
const five = 5;
const one = 1;

function demonstrateOperations() {
    console.log(`Bitwise ${five} AND ${nine}:`, 5 & 9);
    console.log(`Bitwise ${five} OR ${nine}:`, 5 | 9);
    console.log(`Bitwise ${five} XOR ${nine}: `, 5 ^ 9);
    console.log(`Bitwise NOT ${five}: `, ~5);
    console.log(`Bitwise Left Shift ${five} << ${one}: `, 5 << 1);
    console.log(`Bitwise Right Shift ${five} >> ${one}: `, 5 >> 1);
    console.log(`Bitwise Zero Fill Right Shift ${five} >>> ${one}: `, 5 >>> 1);
}

demonstrateOperations();