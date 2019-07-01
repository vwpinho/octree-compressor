
#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/compression/octree_pointcloud_compression.h>

using namespace std;

int main(){
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
        if (pcl::io::loadPLYFile<pcl::PointXYZRGBA> ("longdress_vox10_1051.ply", *cloud) == -1) //* load the file
        {
                PCL_ERROR("Couldn't read the file\n");
                return -1;
        }
        std::cout << "Loaded "
                << cloud->width * cloud->height
                << " data points from test_pcd.pcd with the following fields: "
                << std::endl;

        pcl::io::compression_Profiles_e compressionProfile = pcl::io::MED_RES_ONLINE_COMPRESSION_WITH_COLOR;
        bool showStatistics = true;
        std::stringstream compressedData;
        // instantiate point cloud compression for encoding and decoding
        pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>* PointCloudEncoder;
        pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA>* PointCloudDecoder;
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloudOut (new pcl::PointCloud<pcl::PointXYZRGBA> ());

        PointCloudEncoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> (compressionProfile, showStatistics);
        PointCloudDecoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGBA> ();

        PointCloudEncoder->encodePointCloud (cloud, compressedData);
        
        PointCloudDecoder->decodePointCloud (compressedData, cloudOut);
    return (0);
}
