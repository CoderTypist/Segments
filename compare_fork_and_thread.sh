#!/bin/bash

main() {
    echo "Forking..."
    output_forking=$(./test_fork | sort)
    
    echo "Threading..."
    output_threading=$(./test_thread | sort)

    echo "Merging..."
    lines_forking=()
    while IFS=$'\n' read -r line; do lines_forking+=("${line}"); done < <(echo "${output_forking}")
    lines_threading=()
    while IFS=$'\n' read -r line; do lines_threading+=("${line}"); done < <(echo "${output_threading}")

    num_lines_forking=${#lines_forking[@]}
    num_lines_threading=${#lines_threading[@]}

    if [[ ${num_lines_forking} -ne ${num_lines_threading} ]]; then
        echo "Error: merging: num_lines_forking(${num_lines_forking}) != num_lines_threading(${num_lines_threading})"
        exit 1
    fi
    
    for (( i = 0 ; i < ${num_lines_forking} ; i++ )); do
        echo "| ${lines_forking[${i}]} | ${lines_threading[${i}]} |" 
    done
}

make && main $@
