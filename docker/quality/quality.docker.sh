docker build --no-cache -f Dockerfile.StreamerQuality -t streamer-quality:latest .
docker run --rm -v ~/projects/data/output:/mnt/output -it --name streamer-quality streamer-quality:latest python /Trace/build/python/quality/iqcheck.py ${INPUT0} ${INPUT1}