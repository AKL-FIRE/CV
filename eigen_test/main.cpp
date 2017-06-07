/*
 * main.cpp
 *
 *  Created on: 2017年6月7日
 *      Author: lcy
 */

#include <iostream>
#include <Eigen/Dense>


using namespace Eigen;
using namespace Eigen::internal;
using namespace Eigen::Architecture;

using namespace std;

int main()
{
	Vector4d v1;
	v1 << 1,2,3,4;
	cout << "v1 = " << v1 << endl;

	VectorXd v2(3);
	v2 << 1,2,3;
	cout << "v2 = " << v2 << endl;

	Array4i v3;
	v3 << 1,2,3,4;
	cout << "v3 = " << v3 << endl;

	ArrayXf v4(3);
	v4 << 1,2,3;
	cout << "v4 = " << v4 << endl;

	MatrixXd m(2,2);

	m(0,0) = 3;
	m(1,0) = 2.5;
	m(0,1) = -1;
	m(1,1) = m(1,0)+m(0,1);
	cout << "m = " << m << endl;

	m << 3,-1,2.5,-1.5;
	cout << "m = " << m << endl;

	int rows = 5;
	int cols = 5;
	MatrixXf m1(rows,cols);
	m1 << (Matrix3f() << 1,2,3,4,5,6,7,8,9).finished(),
			MatrixXf::Zero(3,cols-3),
			MatrixXf::Zero(rows-3,3),
			MatrixXf::Identity(rows-3,cols-3);
	cout << "m1 = " << m1 << endl;

	MatrixXf m2(5,4);
	m2 << MatrixXf::Identity(5,4);
	cout << "m2 = " << m2 << endl;

	MatrixXf m3;
	m3 = m1 * m2;
	cout << "m3.rows()=" << m3.rows() << " ; " << "m3.cols()=" << m3.cols() << endl;
	cout << "m3 = " << m3 << endl;

	v1.resize(4);
	cout << "Recover v1 to 4*1 array: v1 = " << v1 << endl;

	m.resize(2,3);
	cout << "Recover m to 2*3 array: m = " << m << endl;
	m.resize(Eigen::NoChange,3);
	cout << "Recover m to 2*3 array: m = " << m << endl;
	m.resizeLike(m2);
	cout << "Recover m to 2*3 array: m = " << m << endl;
	m.resize(2,2);
	cout << "Recover m to 2*3 array: m = " << m << endl;

    //add & sub
    MatrixXf m4(5,4);
    MatrixXf m5;
    m4=m2+m3;
    m3-=m2;

    //product
    m3=m1*m2;

    //transposition
    m5=m4.transpose();
    //m5=m.adjoint();//伴随矩阵

    //dot product
    double xtt;
    cout<<"v1=\n"<<v1<<endl;
    v2.resize(4);
    v2<<VectorXd::Ones(4);
    cout<<"v2=\n"<<v2<<endl;

    cout<<"*************dot product*************"<<endl;
    xtt=v1.dot(v2);
    cout<<"v1.*v2="<<xtt<<endl;

    //vector norm

    cout<<"*************matrix norm*************"<<endl;
    xtt=v1.norm();
    cout<<"norm of v1="<<xtt<<endl;
    xtt=v1.squaredNorm();
    cout<<"SquareNorm of v1="<<xtt<<endl;

    MatrixXf mat(3,3);
    mat << 1,2,3,4,5,6,7,8,9;
    cout << mat << endl;

    MatrixXf mat2 = mat.transpose();
    cout << mat << mat2 << endl;
    cout << mat.eigenvalues() << endl;
}
