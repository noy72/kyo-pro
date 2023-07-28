set -u
RUN=FALSE
NEKO=FALSE
DEBUG=FALSE
TEST=FALSE
OPT=""
OPTIND_SAVE=$OPTIND
VALUE=""

while getopts angt OPT
do
    case $OPT in
        a) RUN=TRUE ;;
        n) NEKO=TRUE ;;
        g) DEBUG=TRUE ;;
        t) TEST=TRUE ;;
        /?) echo "Usage: $0 [-ang] parameter" 1>&2
            exit 1 ;;
    esac
done
shift `expr $OPTIND - 1`

if [ "$RUN" = "TRUE" ]; then
    g++ $1 -std=c++2a -Wall -fsanitize=undefined -D_GLIBCXX_DEBUG && echo "input" && ./a.out
elif [ "$NEKO" = "TRUE" ]; then
    cat $1 | pbcopy
elif [ "$DEBUG" = "TRUE" ]; then
    g++ $1 -g -std=c++2a && lldb a.out
elif [ "$TEST" = "TRUE" ]; then
    g++ $1 -std=c++2a && oj test
else
    echo "only"
    g++ $1 -std=c++2a
fi

OPTIND=$OPTIND_SAVE
