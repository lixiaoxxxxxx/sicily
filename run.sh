name=$1
target=${name%.*}
rm ${target}
g++ ${name} -o ${target}
./${target}
