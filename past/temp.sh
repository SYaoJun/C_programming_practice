rm -rf pipeline_error_file
grep "pipeline error" ./src/test/regress/parallel_schedule* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "Mogdb_copy_schedule">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/Mogdb_copy_schedule* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "Mogdb_compression_schedule">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/Mogdb_compression_schedule* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "Mogdb_reidx_concurrently_schedule">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/Mogdb_reidx_concurrently_schedule* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "Mogdb_compatibility_oracle_schedule">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/Mogdb_compatibility_oracle_schedule* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "Mogdb_regress_enhancement">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/Mogdb_regress_enhancement* >> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
echo "MogDB_compression_table_parallel_schedule0">> pipeline_error_file
echo "--------------------------------------------------------------">> pipeline_error_file
grep "pipeline error" ./src/test/regress/MogDB_compression_table_parallel_schedule0 >> pipeline_error_file
cat pipeline_error_file
#awk '{ print $1  $2 $}' pipeline_error_file