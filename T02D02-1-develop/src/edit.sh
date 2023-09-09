path=$1
oldString=$2
 newString=$3
if test -e "$path"; then
 sed -i '' "s/$oldString/$newString/g" $path
 size=`ls -l $path | awk '{print  $5}'`
 date=`date -r $path "+%Y-%m-%d %H:%M"`
 sum=`shasum -a 256 $path | awk '{print  $1}'`
 isFound=`awk '{print$8}' ./files.log | grep -oc $sum`
 if [[ "$isFound" == 1 ]]; then
   echo "the string $oldString isn't exist in file $path"
 else
   echo "src/$path - $size - $date - $sum - sha256" >> ./files.log
 fi
else
 echo "file $path is not found"
fi
