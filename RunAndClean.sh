#!/bin/bash
path="$1"
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

function ColorExport() {

    # Reset
    export COF='\033[0m' # Color off

    # Regular Colors
    export Black='\033[0;30m'  # Black
    export Red='\033[0;31m'    # Red
    export Green='\033[0;32m'  # Green
    export Yellow='\033[0;33m' # Yellow
    export Blue='\033[0;34m'   # Blue
    export Purple='\033[0;35m' # Purple
    export Cyan='\033[0;36m'   # Cyan
    export White='\033[0;37m'  # White

    # High Intensity
    export IBlack='\033[0;90m'  # Black
    export IRed='\033[0;91m'    # Red
    export IGreen='\033[0;92m'  # Green
    export IYellow='\033[0;93m' # Yellow
    export IBlue='\033[0;94m'   # Blue
    export IPurple='\033[0;95m' # Purple
    export ICyan='\033[0;96m'   # Cyan
    export IWhite='\033[0;97m'  # White

    # Bold High Intensity
    export BIBlack='\033[1;90m'  # Black
    export BIRed='\033[1;91m'    # Red
    export BIGreen='\033[1;92m'  # Green
    export BIYellow='\033[1;93m' # Yellow
    export BIBlue='\033[1;94m'   # Blue
    export BIPurple='\033[1;95m' # Purple
    export BICyan='\033[1;96m'   # Cyan
    export BIWhite='\033[1;97m'  # White

    # High Intensity backgrounds
    export On_IBlack='\033[0;100m'  # Black
    export On_IRed='\033[0;101m'    # Red
    export On_IGreen='\033[0;102m'  # Green
    export On_IYellow='\033[0;103m' # Yellow
    export On_IBlue='\033[0;104m'   # Blue
    export On_IPurple='\033[0;105m' # Purple
    export On_ICyan='\033[0;106m'   # Cyan
    export On_IWhite='\033[0;107m'  # White
}

Compile() {
    echo -e "${Green}Starting compiling...${COF}"
    if g++ "$path" -o "result.out"; then
        echo -e "${IBlue}Compilation successful${COF}"
        chmod +x "result.out"
        ./result.out
    else
        echo -e "${IRed}Failed to compile${COF}"
    fi
}

Clean() {
    echo -e "${IYellow}Cleaning up...${COF}"
    find "$SCRIPT_DIR" -type f -name "*.out" -exec rm -f {} \;
}

ColorExport
Compile
Clean
