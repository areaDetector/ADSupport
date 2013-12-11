#
# In the current working directory, renames all files ending in ".h" to end in
# "_ad.h", and replaces all occurences of the ".h" file names in all files
# ending in ".h" or ".c" with the new "_ad.h" names.
#
# Yes, this is quick, dirty, and very inefficient.
#

for each in `ls -1 *.h`; do
  escEach=`echo "$each" | sed -e 's/\./\\\\./g'`
  noExtEach="${each%.h}"
  for eachSrc in `ls -1 *.h *.c`; do
    newEachSrc="$each.new"
    sed -e "s/$escEach/${noExtEach}_ad.h/g" "$eachSrc" > "$newEachSrc" && \
      mv -f "$newEachSrc" "$eachSrc"
  done
done

for each in `ls -1 *.h`; do
  noExtEach="${each%.h}"
  mv "$each" "${noExtEach}_ad.h"
done
