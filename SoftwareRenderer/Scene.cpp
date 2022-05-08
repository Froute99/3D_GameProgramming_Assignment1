#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"
#include "Rail.h"


CScene::CScene(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{
	//CExplosiveObject::PrepareExplosion();

	//float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	//CWallMesh* pWallCubeMesh = new CWallMesh(fHalfWidth * 2.0f, fHalfHeight * 2.0f, fHalfDepth * 2.0f, 30);

	//m_pWallsObject = new CWallsObject();
	//m_pWallsObject->SetPosition(0.0f, 0.0f, 0.0f);
	//m_pWallsObject->SetMesh(pWallCubeMesh);
	//m_pWallsObject->SetColor(RGB(0, 0, 0));
	//m_pWallsObject->m_pxmf4WallPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	//m_pWallsObject->m_pxmf4WallPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	//m_pWallsObject->m_pxmf4WallPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	//m_pWallsObject->m_pxmf4WallPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	//m_pWallsObject->m_pxmf4WallPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	//m_pWallsObject->m_pxmf4WallPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	//m_pWallsObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));


	const float railWidth = 4.f;
	const float halfRailWidth = railWidth * 0.5f;
	const float halfRailDepth = 1.2f;

	CCubeMesh* pCubeMesh = new CCubeMesh(1.0f, 1.0f, 3.0f);

	m_nObjects = 60;
	m_ppObjects = new CGameObject * [m_nObjects];

	const float xBase = 0.f;
	const float yBase = 0.f;
	const float zBase = 0.f;
	const float offset = 5.f;

	//m_ppObjects[0] = new CGameObject;
	//m_ppObjects[0]->SetMesh(pCubeMesh);
	//m_ppObjects[0]->SetColor(RGB(255, 0, 0));

	//m_ppObjects[1] = new CGameObject;
	//m_ppObjects[1]->SetMesh(pCubeMesh);
	//m_ppObjects[1]->SetColor(RGB(255, 0, 0));

	//m_ppObjects[2] = new CGameObject;
	//m_ppObjects[2]->SetMesh(pCubeMesh);
	//m_ppObjects[2]->SetColor(RGB(255, 0, 0));

	float degree = -6.f;

	//XMFLOAT4X4 t0 = Matrix4x4::Translate(5.f, 0.f, 0.f);
	//XMFLOAT4X4 r0 = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, 0.f);
	//m_ppObjects[0]->m_xmf4x4World = Matrix4x4::Multiply(t0, r0);


	//XMFLOAT3 basePos = m_ppObjects[0]->GetPosition();

	//XMFLOAT4X4 t1 = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
	//XMFLOAT4X4 r1 = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, -15.f);
	//m_ppObjects[1]->m_xmf4x4World = Matrix4x4::Multiply(t1, r1);


	//XMFLOAT4X4 t2 = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
	//XMFLOAT4X4 r2 = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, -30.f);
	//m_ppObjects[2]->m_xmf4x4World = Matrix4x4::Multiply(t2, r2);

	XMFLOAT3 basePos = XMFLOAT3{ 15.f, 0.f, 0.f };
	for (int i = 0; i < 60; ++i) {
		m_ppObjects[i] = new CGameObject;
		m_ppObjects[i]->SetMesh(pCubeMesh);
		m_ppObjects[i]->SetColor(RGB(255, 0, 0));

		XMFLOAT4X4 t = Matrix4x4::Translate(basePos.x, basePos.y, basePos.z);
		XMFLOAT4X4 r = Matrix4x4::RotationAxis(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, degree * i);
		m_ppObjects[i]->m_xmf4x4World = Matrix4x4::Multiply(t, r);

		//basePos = m_ppObjects[i]->GetPosition();
	}



	//m_ppObjects[2] = new CGameObject;
	//m_ppObjects[2]->SetMesh(pCubeMesh);
	//m_ppObjects[2]->SetColor(RGB(255, 0, 0));
	//m_ppObjects[2]->SetPosition(7.2f, 0.f, 10.f);
	//m_ppObjects[2]->Rotate(DirectX::XMFLOAT3{ 0.f, 1.f, 0.f }, -30.f);

	//for (int i = 0; i < m_nObjects; ++i) {
	//	m_ppObjects[i] = new CRail({ xBase, yBase, zBase + offset * i });
	//}


	//m_ppObjects[0] = new CRail({ 0.f, 0.0f, 0.0f });
	//m_ppObjects[0]->SetMesh(pCubeMesh);
	//m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	//m_ppObjects[0]->SetPosition(0.f, 0.0f, 0.0f);

	//m_ppObjects[1] = new CRail({ 0.f, 0.0f, 7.5f });
	//m_ppObjects[1]->SetMesh(pCubeMesh);
	//m_ppObjects[1]->SetColor(RGB(255, 0, 0));
	//m_ppObjects[1]->SetPosition(0.f, 0.0f, 7.5f);

	//m_ppObjects[0] = new CExplosiveObject();
	//m_ppObjects[0]->SetMesh(pCubeMesh);
	//m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	//m_ppObjects[0]->SetPosition(-13.5f, 0.0f, -14.0f);
	//m_ppObjects[0]->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	//m_ppObjects[0]->SetRotationSpeed(90.0f);
	//m_ppObjects[0]->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 0.0f));
	//m_ppObjects[0]->SetMovingSpeed(10.5f);



#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	//if (m_pWallsObject) delete m_pWallsObject;

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			//case '1':
			//case '2':
			//case '3':
			//case '4':
			//case '5':
			//case '6':
			//case '7':
			//case '8':
			//case '9':
			//{
			//	CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[int(wParam - '1')];
			//	pExplosiveObject->m_bBlowingUp = true;
			//	break;
			//}
			//case 'A':
			//	for (int i = 0; i < m_nObjects; i++)
			//	{
			//		CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
			//		pExplosiveObject->m_bBlowingUp = true;
			//	}
			//	break;
		case 'R':
			auto initialPosition = m_ppObjects[0]->GetPosition();
			m_pPlayer->SetPosition(initialPosition);
			break;
		case 'W':
			//float movingSpeed = (m_ppObjects[0]->GetPosition().z
			//	- m_ppObjects[1]->GetPosition().z) / 60.f;
			//m_pPlayer->SetMovingDirection(DirectX::XMFLOAT3{ 0.f, 0.f, 1.f });
			//m_pPlayer->SetMovingSpeed((m_ppObjects[1]->GetPosition().z
			//	- m_ppObjects[0]->GetPosition().z));

			//m_pPlayer->m_xmf3Velocity.z = 1.f;
			isCoasterMoving = true;

			//DirectX::XMFLOAT3 currPosition = m_pPlayer->GetPosition();
			//m_pPlayer->SetPosition(DirectX::XMFLOAT3{ currPosition.x, currPosition.y, currPosition.z + 1.f });
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject* pNearestObject = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppObjects[i];
		}
	}
	return(pNearestObject);
}

void CScene::CheckObjectByObjectCollisions()
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = (i + 1); j < m_nObjects; j++)
		{
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB))
			{
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nObjects; i++)
	{
		if (m_ppObjects[i]->m_pObjectCollided)
		{
			XMFLOAT3 xmf3MovingDirection = m_ppObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppObjects[i]->m_fMovingSpeed;
			m_ppObjects[i]->m_xmf3MovingDirection = m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppObjects[i]->m_fMovingSpeed = m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppObjects[i]->m_pObjectCollided = NULL;
		}
	}
}

void CScene::CheckObjectByWallCollisions()
{
	for (int i = 0; i < m_nObjects; i++)
	{
		ContainmentType containType = m_pWallsObject->m_xmOOBB.Contains(m_ppObjects[i]->m_xmOOBB);
		switch (containType)
		{
		case DISJOINT:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == BACK)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case INTERSECTS:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == INTERSECTING)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case CONTAINS:
			break;
		}
	}
}

void CScene::CheckPlayerByWallCollision()
{
	BoundingOrientedBox xmOOBBPlayerMoveCheck;
	//m_pWallsObject->m_xmOOBBPlayerMoveCheck.Transform(xmOOBBPlayerMoveCheck, XMLoadFloat4x4(&m_pWallsObject->m_xmf4x4World));
	XMStoreFloat4(&xmOOBBPlayerMoveCheck.Orientation, XMQuaternionNormalize(XMLoadFloat4(&xmOOBBPlayerMoveCheck.Orientation)));

	//if (!xmOOBBPlayerMoveCheck.Intersects(m_pPlayer->m_xmOOBB)) m_pWallsObject->SetPosition(m_pPlayer->m_xmf3Position);
}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CAirplanePlayer*)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
				ppBullets[j]->Reset();
			}
		}
	}
}

void CScene::Animate(float fElapsedTime)
{
	//m_pWallsObject->Animate(fElapsedTime);

	for (int i = 0; i < m_nObjects; i++)
		m_ppObjects[i]->Animate(fElapsedTime);

	if (isCoasterMoving) {
		m_pPlayer->m_xmf3Velocity.x = (m_ppObjects[1]->GetPosition().x - m_ppObjects[0]->GetPosition().x) / 100.f;
		m_pPlayer->m_xmf3Velocity.y = (m_ppObjects[1]->GetPosition().y - m_ppObjects[0]->GetPosition().y) / 100.f;
		m_pPlayer->m_xmf3Velocity.z = (m_ppObjects[1]->GetPosition().z - m_ppObjects[0]->GetPosition().z) / 100.f;
		DirectX::XMFLOAT3 currPosition = m_pPlayer->GetPosition();
		m_pPlayer->SetPosition(DirectX::XMFLOAT3{
			currPosition.x + m_pPlayer->m_xmf3Velocity.x * fElapsedTime,
			currPosition.y + m_pPlayer->m_xmf3Velocity.y * fElapsedTime,
			currPosition.z + m_pPlayer->m_xmf3Velocity.z * fElapsedTime });
		if (m_pPlayer->GetPosition().z > m_ppObjects[1]->GetPosition().z) {
			isCoasterMoving = false;
		}
	}

	//CheckPlayerByWallCollision();

	//CheckObjectByWallCollisions();

	//CheckObjectByObjectCollisions();

	//CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);

	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);
	//m_pWallsObject->Render(hDCFrameBuffer, pCamera);
	for (int i = 0; i < m_nObjects; i++)
		m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);

	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);

//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}
