const { execSync } = require('child_process');
const { writeFileSync } = require('fs');
const _ = require('lodash'),
    xmlbuilder = require('xmlbuilder');

let allBranches = 
    execSync('git branch -r').toString()    //Get all remote branches
    .trim()                                 //Trim ending whitespace
    .split('\n')                            //Split by newline
    .slice(1)                               //Remove first entry (origin/HEAD)
    .map( (str) => str.trim() );            //Trim each entry

var xml = xmlbuilder.create('branches');
allBranches.forEach( ( branch ) => {
    let branchName = branch.substring(branch.lastIndexOf("/")+1);
    xml.ele("branch", { "shortName" : branchName }, branch);
});
let xmlString = xml.end({ pretty: true});

writeFileSync("git_xml.xml", xmlString); 