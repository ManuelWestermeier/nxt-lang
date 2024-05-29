console.clear()
const fs = require('fs')
const path = require('path')

const inputPath = "../code/index.nl"
const outPath = "../out/index.cpp"

var top = ""
const code = compile(inputPath)

var output = `${top}
${fs.readFileSync("std/index.cpp", "utf-8")}
int main (int argc, char** argv) {
    ${code}
}`

function template(pathName, templateName) {
    const template = fs.readFileSync(pathName, "utf-8").split("$$").map((part, i) => {
        if (i % 2 == 1)
            return ` + ${part} + `
        else return part.replace(/\n/g, "\\n")
            .replace(/\r/g, "\\r")
            .replace(/\t/g, "\\t")
            .replace(/"/g, '\\"')
    }).join('"')

    return `string ${templateName} = "${template}";`
}

function compile(pathName) {
    var code = fs.readFileSync(pathName, "utf-8")

    return code.replace(/\r/g, "").split("\n").map(line => {
        const replacedLineParts = line.replace(/\t|  /g, "").split(" ")

        if (replacedLineParts?.[0] == "@add") {
            return compile(path.join(path.dirname(pathName), replacedLineParts[1]))
        }
        if (replacedLineParts?.[0] == "@template") {
            return template(
                path.join(path.dirname(pathName),
                    replacedLineParts?.[3]), replacedLineParts[1]
            )
        }
        if (replacedLineParts?.[0]?.[0] == "#") {
            top += line;
            return "//on top " + line;
        }

        return line
    }).join("\n")
}

fs.writeFileSync(outPath, output, "utf-8")