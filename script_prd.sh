git checkout prd

git merge stg

git tag $(date '+%Y-%m-%d-%H-%M-%S')

git push --tags

git push

git checkout dev
